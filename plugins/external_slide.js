/**
 * Inspired by:
 *  - https://github.com/dafrenchyman/reveal.js-extrernal-code/blob/master/externalcode.js
 *  - https://github.com/janschoepke/reveal_external/blob/master/external/external.js
 */

const ExternalSlide = {
    id: "externalcode",
    init: (reveal) => {
        
        function fetchDataExternalSlideSection(section, attribute, replace) {
            url = section.getAttribute(attribute);
            return fetch(url)
              .then((response) => response.text())
              .then((data) => {
                //section.innerHTML = data;
                html = ( new DOMParser ).parseFromString(
                    data, 'text/html'
                );
                nodes = html.querySelector( 'body' ).childNodes
                for ( var i = 0, c = nodes.length; i < c; i++ ) {
                    node = document.importNode( nodes[i], true );
                    replace
                        ? section.parentNode.insertBefore( node, section )
                        : section.appendChild( node );

                    // TODO: Implement recursion
                }

                if ( replace ) {
                    section.parentNode.removeChild( section );
                }
              });
        }

        var sections = document.querySelectorAll("[data-external-slide], [data-external-slide-replace]");
        var promiseArray = new Array(sections.length);

        for (var i = 0, len = sections.length; i < len; i++) {
            section = sections[i];
            if (section.getAttribute("data-external-slide") != null) {
                promiseArray[i] = fetchDataExternalSlideSection(section, "data-external-slide", false);
            }
            else if (section.getAttribute("data-external-slide-replace") != null) {
                promiseArray[i] = fetchDataExternalSlideSection(section, "data-external-slide-replace", true);
            }
        }
        return Promise.all(promiseArray);
    },
}
