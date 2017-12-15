import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        name: "singleWordString"
        cpp.cxxFlags: "-std=c++11"
        consoleApplication: true
        files: "main.cpp"

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
