# Prime Factoring
While this assignment is intended to be about factoring and
algorithms, as neither of these topics are things I needed
to cover, I instead spent my time getting familiar with
CMocka for unit testing, porting my prior TUI library into
a standalone package that is managed via Conan, and building
out a Conan environment with this package to make it package
friendly.  

I'm currently dissatisfied with the design and structure of
my testing suite.  I'm a proponent of table-driven test design
and the lack of native, easy, dynamic memory makes it challenging
to abide to this philosophy.  I'll be looking into light weight
HashMap and Vector implementations before too long to expedite 
this type of testing, though I'm unsure how long you would like
me to develop "with my hands tied" (manually handling all 
structure type definitions and implementation vs using common
libraries).  
