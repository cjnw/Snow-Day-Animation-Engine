# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-src"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-build"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-subbuild/box2d-populate-prefix"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-subbuild/box2d-populate-prefix/tmp"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-subbuild/box2d-populate-prefix/src"
  "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/cjcn8/OneDrive - Michigan State University/CSE 335/project2/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
