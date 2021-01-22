/**
 * Inspired by:
 *  - https://github.com/dafrenchyman/reveal.js-extrernal-code/blob/master/externalcode.js
 *  - https://github.com/janschoepke/reveal_external/blob/master/external/external.js
 */

const ExternalSlide = {
    id: "externalslide",
    init: (reveal) => {
        function fetchDataExternalSlideSection(section, attribute, replace, nesting_level) {
            url = section.getAttribute(attribute);
            return fetch(url)
                .then((response) => response.text())
                .then((data) => {
                    //section.innerHTML = data;
                    html = (new DOMParser).parseFromString(data, 'text/html');
                    nodes = html.querySelector('body').childNodes
                    var promiseArray = new Array();
                    for (var i = 0, c = nodes.length; i < c; i++) {
                        node = document.importNode(nodes[i], true);
                        replace || nesting_level > 1
                            ? section.parentNode.insertBefore(node, section)
                            : section.appendChild(node);

                        // Recurse nested slides
                        if (node instanceof Element) {
                            v = fetchContent(node, nesting_level)
                            if (v) {
                                promiseArray.push(v);
                            }
                        }
                    }

                    if (replace || nesting_level > 1) {
                        section.parentNode.removeChild(section);
                    }

                    return Promise.all(promiseArray);
                });
        }

        function fetchContent(section, nesting_level) {
            if (section.getAttribute("data-external-slide") != null) {
                return fetchDataExternalSlideSection(section, "data-external-slide", false, nesting_level + 1);
            }
            else if (section.getAttribute("data-external-slide-replace") != null) {
                return fetchDataExternalSlideSection(section, "data-external-slide-replace", true, nesting_level);
            }
            return null
        }

        var sections = document.querySelectorAll("[data-external-slide], [data-external-slide-replace]");
        var promiseArray = new Array(sections.length);

        for (var i = 0, len = sections.length; i < len; i++) {
            promiseArray[i] = fetchContent(sections[i], 0)
        }

        return Promise.all(promiseArray).then(() => {
            console.log('ExternalSlide: All slides loaded successfully!');
        });
    },
}
