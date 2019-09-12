The AnyConnect Updater Plugin Library enables OTA firmware updates in conjunction with the AnyConnect Smarter Camera Platform.
The steps to build and deploy your Updater Library are:

1. Complete the stub functions in Update.cpp.
2. Compile your libupdater.so.
3. Copy the libupdater.so in the lib directory of your smart camera application.


What’s Included:

- README            Instructions to complete the Update.cpp stub functions and compile and use libupdater.so.
- Update.h          Updater library header file.  This derived class overrides UpdateService base class member functions.
- Update.cpp        Updater library source file.  You must complete the stub functions.
- UpdateService.h   These base class member functions are overridden by Update derived class.
- CMakeLists.txt    Compiles libupdater.so.
- test/Test.h       Test application header for libupdater.so.
- test/Test.cpp     Test application for libupdater.so.
- test/CMakeLists.txt   Compiles the test application.


What’s Required:

Software packages:
- Linux
- dl library
- pthreads library 
- gcc/g++ version 7.x or higher


How to complete the Update.cpp stub functions:

1. Fill out the 'update()' function with the download, extract and flashing code.
2. Use the 'UpdateStatusHandler' function callback for any kind of update status return.


How to compile your Updater Library.

Compile your libupdater.so by typing 'cmake . && make all'

How to test your compiled Updater Library.

Compile the test application by typing “cd test/ && cmake . && make all”.  This will generate a test application called “updatetest”. Run the test application by typing "./updatetest”.  

If successful, the test application will print “Your AnyConnect Updater Library loads!”.  If not successful, the test application will print “Your AnyConnect Updater Library does not load.”.
