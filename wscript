#! /usr/bin/env python
# encoding: utf-8
'''
@file wscript
@brief This is the main Waf based build sytem file for SSE-ImGui

This file is part of Skyrim SE ImGui mod project (aka SSE-ImGui).

  SSE-ImGui is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published
  by the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  SSE-ImGui is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with SSE-ImGui. If not, see <http://www.gnu.org/licenses/>.

@endinternal

@ingroup Builds

@details
Waf is Python (2/3) based build system similar to SCons & Make.
@see https://waf.io/book/
'''

import os

#---------------------------------------------------------------------------------------------------

top = '.'
''' Representing the project directory, relative to this wscript. In general, set to .'''

out = 'out'
''' String representing the build directory. Can be an absolute path too. It is important to be 
able to remove the build directory safely, so it should never be given as . or similar. '''

APPNAME = 'sse-imgui'
''' Used to specify the generated executable names and the generated distribution archive name. '''

VERSION = open ('VERSION', 'r').readline ().strip ().replace (',', '.') 
''' The version field is used accross the project: for distro tars, for documentation, for file
stamps and etc. It is taken from central file - useful to share accross its users. '''

#---------------------------------------------------------------------------------------------------

def options(opt):
    opt.load('compiler_cxx')

def configure(conf):
    conf.load('compiler_cxx')

    if conf.env['CXX_NAME'] == 'gcc':
        conf.check_cxx (msg="Checking for '-std=c++20'", cxxflags='-std=c++20') 
        conf.env.append_unique('CXXFLAGS', \
                ['-std=c++20', "-O2", "-Wall", "-D_UNICODE", "-DUNICODE"])
        conf.env.append_unique ('STLIB', ['stdc++', 'pthread', 'ole32', 'imm32', 'gdi32', 'dwmapi'])
        conf.env.append_unique ('LINKFLAGS', ['-static-libgcc', '-static-libstdc++'])
    elif conf.env['CXX_NAME'] == 'msvc':
        conf.env.append_unique('CXXFLAGS', ['/EHsc', '/MT', '/O2'])

def build (bld):
    bld.shlib (
        target   = APPNAME, 
        source   = bld.path.ant_glob (["src/*.cpp", "share/imgui/*.cpp", "share/cimgui/*.cpp", \
                "share/utils/*.cpp", "share/DDSTextureLoader/*.cpp", "share/font-compress/*.cpp"], 
            excl=["src/test_*.cpp"]), 
        includes = ['src', 'include', 'share'],
        cxxflags = ['-DSSEIMGUI_BUILD_API', '-DSSEIMGUI_TIMESTAMP="'+str(_datetime_now())+'"', 
            '-DCIMGUI_NO_EXPORT'])
    for src in bld.path.ant_glob ("src/test_*.cpp"):
        f = os.path.basename (str (src))
        f = os.path.splitext (f)[0]
        bld.program (target=f, source=[src], includes='include', use=APPNAME)

def pack (bld):
    import shutil, subprocess
    shutil.rmtree ("Data", ignore_errors=True)
    dll = APPNAME+".dll"
    root = "Data/SKSE/Plugins/"
    os.makedirs (root)
    shutil.copyfile ("out/"+dll, root+dll)
    subprocess.Popen (["x86_64-w64-mingw32-strip", "-g", root+dll]).communicate ()
    subprocess.Popen (["7z", "a", APPNAME+"-"+VERSION+".7z", 'Data']).communicate ()
    shutil.rmtree ("Data", ignore_errors=True)

#---------------------------------------------------------------------------------------------------

def _datetime_now ():
    from datetime import datetime, timedelta, tzinfo
    """ Python 3.2 and less miss timezones."""
    class UTC (tzinfo):
        def utcoffset (self, dt):
            return timedelta (0)
        def tzname (self, dt):
            return "UTC"
        def dst (self, dt):
            return timedelta (0)
    return datetime.now (UTC ()).isoformat ()

#---------------------------------------------------------------------------------------------------
