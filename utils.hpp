/*
 *  Copyright (c) Hubert Jarosz. All rights reserved.
 *  Licensed under the MIT license. See LICENSE file in the project root for full license information.
 */

#pragma once

#include <cstdlib>
#include <set>
#include <string>
#include <cstring>

// Prototype of the coreclr_initialize function from the libcoreclr.so
typedef int (coreclrInitializeFunction)(
            const char* exePath,
            const char* appDomainFriendlyName,
            int propertyCount,
            const char** propertyKeys,
            const char** propertyValues,
            void** hostHandle,
            unsigned int* domainId);

// Prototype of the coreclr_shutdown function from the libcoreclr.so
typedef int (coreclrShutdownFunction)(
            void* hostHandle,
            unsigned int domainId);

// Prototype of the coreclr_execute_assembly function from the libcoreclr.so
typedef int (coreclrCreateDelegateFunction)(
              void* hostHandle,
              unsigned int domainId,
              const char* entryPointAssemblyName,
              const char* entryPointTypeName,
              const char* entryPointMethodName,
              void** delegate);



#include <filesystem>

void AddFilesFromDirectoryToTpaList( std::string directory, std::string& tpaList ) {

  for ( auto& dirent : std::filesystem::directory_iterator(directory) ) {
    std::string path = dirent.path();

    if ( ! path.compare(path.length() - 4, 4, ".dll") ) {
      tpaList.append(path + ":");
    }
  }

}
