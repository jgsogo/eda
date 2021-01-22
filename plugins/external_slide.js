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

            // Make syncronous call (no 'fetch') because we need all the slides before initializing Reveal
            var xhr = new XMLHttpRequest();
            xhr.onreadystatechange = function () {
                if (xhr.readyState === 4) {
                    console.log('onready')
                    if ((xhr.status >= 200 && xhr.status < 300) || (xhr.status === 0 && xhr.responseText !== '')) {
                        html = (new DOMParser).parseFromString(xhr.responseText, 'text/html');
                        nodes = html.querySelector('body').childNodes
                        section.innerHTML = '';
                        for (var i = 0, c = nodes.length; i < c; i++) {
                            node = document.importNode(nodes[i], true);
                            replace || nesting_level > 1
                                ? section.parentNode.insertBefore(node, section)
                                : section.appendChild(node);

                            // Recurse nested slides
                            if (node instanceof Element) {
                                v = fetchContent(node, nesting_level)
                                if (v) {
                                    Promise.resolve(v);
                                }
                            }
                        }

                        if (replace || nesting_level > 1) {
                            section.parentNode.removeChild(section);
                        }
                    }
                    else {
                        console.log(
                            'ERROR: The attempt to fetch ' + url +
                            ' failed with HTTP status ' + xhr.status + '.'
                        );
                    }
                }
            };


            xhr.open("GET", url);
            try {
                xhr.send();
            }
            catch (e) {
                console.log(
                    'Failed to get the file ' + url +
                    '. Make sure that the presentation and the file are served by a ' +
                    'HTTP server and the file can be found there. ' + e
                );
            }
            /*
            return fetch(url)
                .then((response) => response.text())
                .then((data) => {
                    console.log(data)
                    //section.innerHTML = data;
                    html = (new DOMParser).parseFromString(data, 'text/html');
                    nodes = html.querySelector('body').childNodes
                    for (var i = 0, c = nodes.length; i < c; i++) {
                        node = document.importNode(nodes[i], true);
                        replace || nesting_level > 1
                            ? section.parentNode.insertBefore(node, section)
                            : section.appendChild(node);

                        // Recurse nested slides
                        if (node instanceof Element) {
                            v = fetchContent(node, nesting_level)
                            if (v) {
                                Promise.resolve(v);
                            }
                        }
                    }

                    if (replace || nesting_level > 1) {
                        section.parentNode.removeChild(section);
                    }
                });
            */
        }

        function fetchContent(section, nesting_level) {
            if (section.getAttribute("data-external-slide") != null) {
                fetchDataExternalSlideSection(section, "data-external-slide", false, nesting_level + 1);
            }
            else if (section.getAttribute("data-external-slide-replace") != null) {
                fetchDataExternalSlideSection(section, "data-external-slide-replace", true, nesting_level);
            }
        }

        var sections = document.querySelectorAll("[data-external-slide], [data-external-slide-replace]");
        var promiseArray = new Array(sections.length);

        for (var i = 0, len = sections.length; i < len; i++) {
            //promiseArray[i] = fetchContent(sections[i], 0)
            fetchContent(sections[i], 0);
        }
        return new Promise(resolve => setTimeout(resolve, 10000))
        //return Promise.all(promiseArray);
    },
}
