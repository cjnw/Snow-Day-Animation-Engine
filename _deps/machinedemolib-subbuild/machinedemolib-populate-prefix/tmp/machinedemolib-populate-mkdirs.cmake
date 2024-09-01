# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-src"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-build"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/tmp"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/machinedemolib-subbuild/machinedemolib-populate-prefix/src/machinedemolib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
