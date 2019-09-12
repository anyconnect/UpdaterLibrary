#include "Test.h"
#include "UpdateService.h"
#include <assert.h>
#include <dlfcn.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>

Test::Test()
{
}

void Test::loadLib(std::string name)
{
    instance = NULL;
    handle = dlopen(name.c_str(), RTLD_LAZY);

    if (!handle)
    {
        printf("%s\n", dlerror());
        return;
    }

    create = (UpdateService * (*)()) dlsym(handle, "create");
    destroy = (void (*)(UpdateService *)) dlsym(handle, "destroy");

    char *error;
    if ((error = dlerror()) != NULL)
    {
        printf("%s\n", error);
        return;
    }

    instance = create();
}

bool Test::isLoaded()
{
    return instance != NULL;
}

void Test::setUpdateCallback()
{
    instance->setUpdateStatusCallback([this](std::string version, std::string url, UpdateStatus status) {
            std::cout << "Update status received for: " << version << " download URL: " << url << std::endl;
    });
}

Test::~Test()
{
    destroy(instance);
    dlclose(handle);
    handle = NULL;
}

Test *pTest = new Test();

int main()
{
    pTest->loadLib("./libupdater.so");

    if (pTest->isLoaded())
    {
        printf("Your AnyConnect Updater Library is loaded!\n");
    }
    else
    {
        printf("Your AnyConnect Updater Library is not loaded!\n");
        return 0;
    }
    pTest->setUpdateCallback();
    while (1)
    {
        sleep(3);
    }
    return 0;
}
