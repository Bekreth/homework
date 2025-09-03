from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class lab_05Recipe(ConanFile):
    name = "lab_05"
    version = "1.0.0"
    package_type = "application"

    # Optional metadata
    license = "<Put the package license here>"
    author = "Christopher"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "Homework assignment for lab 5"
    topics = ("<Put some tag here>", "<here>", "<and here>")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def requirements(self):
        self.requires("cmocka/1.1.7")
        self.requires("tui/0.1")

    def package(self):
        cmake = CMake(self)
        cmake.install()

    

    
