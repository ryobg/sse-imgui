#!/usr/bin/env python 
# encoding: utf-8

from mako.template import Template
from mako.lookup import TemplateLookup
from mako.runtime import Context
from mako.exceptions import RichTraceback
from io import FileIO
from io import TextIOWrapper
from shutil import copyfile

lines = []
with open ("share/cimgui/cimgui.h") as f:
    for l in f.readlines ():
        if l.startswith ("CIMGUI_API"):
            lines.append (l)
api = []
names = []
for l in lines:
    p = l[:l.find ('(')]
    p = p.split ()
    n = p[-1]
    names.append (n)
    prefix = ' '.join (p[1:-1]).strip ()
    suffix = l[l.find ('('):].strip ()
    p = [prefix, n, suffix]
    api.append (p)

def output (template, destination, **kwargs):
    out = TextIOWrapper (FileIO (destination, 'w'), encoding='utf8', newline='\n')
    lookup = TemplateLookup (directories=["src"], output_encoding='utf8', input_encoding='utf8')
    t = lookup.get_template (template)
    try:
        t.render_context (Context (out, **kwargs))
    except:
        traceback = RichTraceback ()
        for (filename, lineno, function, line) in traceback.traceback:
            print ("File %s, line %s, in %s" % (filename, lineno, function))
            print (line, "\n")
    finally:
        out.close()

output ("imgui_wrapped_h.mako", "include/sse-imgui/imgui_wrapped.h", api = api)
output ("imgui_wrapped_cpp.mako", "src/imgui_wrapped.cpp", names = names)
copyfile ("share/cimgui/cimgui.h", "include/sse-imgui/cimgui.h")
