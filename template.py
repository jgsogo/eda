import os
from jinja2 import Template, FileSystemLoader, Environment
import yaml

me = os.path.dirname(__file__)
toc_file = 'toc.html'


def generate_graphviz(base_folder):
    for root, subdirs, files in os.walk(base_folder):
        for file in files:
            if file.endswith('.dot'):
                input_file = os.path.join(root, file)
                output_file = os.path.join(root, file + '.png')
                print(f"{input_file} -> {output_file}")
                os.system(f"dot -Tpng {input_file} > {output_file}")


if __name__ == '__main__':
    with open(os.path.join(me, 'template.yml')) as f:
        content = yaml.safe_load(f.read())

    templateLoader = FileSystemLoader(searchpath=os.path.join(me, 'templates'))
    templateEnv = Environment(loader=templateLoader)
    template = templateEnv.get_template('template.html.tpl')


    section_content = []
    toc = [('', section_content)]
    for item in content['toc']:
        if 'section' in item:
            section_content = []
            toc.append((item['section'], section_content))
            continue

        url = item.pop('url', item.get('content_main').replace('slides/', ''))
        section_content.append((url, item['title']))

        outputText = template.render(url=url, toc_file=toc_file, **item)
        with open(os.path.join(me, url), 'w') as f:
            f.write(outputText)

    with open(os.path.join(me, toc_file), 'w') as f:
        f.write('<h1>{}</h1>\n\n'.format(content['title']))
        
        for title, contents in toc:
            if title:
                f.write('<h2>{}</h2>\n'.format(title))
            
            f.write('<ul class="slide-menu-items">\n')
            for url, ctitle in contents:
                f.write('\t<li class="slide-menu-item">\n')
                f.write('\t\t<a href="{}">{}</a>\n'.format(url, ctitle))
                f.write('\t</li>\n')
            f.write('</ul>\n\n')

    # Generate all the graphs
    generate_graphviz(me)
