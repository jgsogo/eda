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
            console.log(`Lazy load '${url}'`)
            return fetch(url)
                .then((response) => response.text())
                .then((data) => {
                    //section.innerHTML = '';
                    html = (new DOMParser).parseFromString(data, 'text/html');
                    nodes = html.querySelector('body').childNodes
                    // Add sections
                    var promiseArray = new Array();
                    for (var i = 0, c = nodes.length; i < c; i++) {
                        node = document.importNode(nodes[i], true);
                        if (node instanceof Element) {
                            replace || nesting_level > 1
                                ? section.parentNode.insertBefore(node, section)
                                : section.appendChild(node);

                            // Maybe itself contains a 'data-external-slide[-replace]
                            if (node.getAttribute('data-external-slide-replace') || node.getAttribute('data-external-slide')) {
                                promiseArray.push(fetchContent(node, nesting_level + 1))
                            }
                            else {
                                var nested_sections = node.querySelectorAll("[data-external-slide], [data-external-slide-replace]");
                                for (var ii = 0, len = nested_sections.length; ii < len; ii++) {
                                    promiseArray.push(fetchContent(nested_sections[ii], nesting_level + 1))
                                }
                            }
                        }
                    }

                    if (replace || nesting_level > 1) {
                        section.parentNode.removeChild(section);
                    }

                    // Add headers
                    headers = html.querySelectorAll('head link')
                    for (var i = 0, c = headers.length; i < c; i++) {
                        header = document.importNode(headers[i], true);
                        document.head.appendChild(header);
                    }

                    // Add scripts (after Reveal is ready)
                    scripts = html.querySelectorAll('head script')
                    for (var i = 0, c = scripts.length; i < c; i++) {
                        var spt = scripts[i];
                        ((type, src, text) => {
                            Reveal.addEventListener('ready', function (event) {
                                var injectScript = document.createElement("script");
                                injectScript.type = type;
                                injectScript.text = text;
                                if (src) {
                                    injectScript.src = src;
                                }
                                document.body.appendChild(injectScript);
                            })
                        })(spt.type, spt.src, spt.text);
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
