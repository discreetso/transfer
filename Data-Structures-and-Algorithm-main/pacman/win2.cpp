// Assignment 1 - FileInfoCopy - CS609 - Fall 2025

#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    HANDLE hFile;
    DWORD bytesWritten, bytesRead;
    BOOL success;
    const char* data = "BC020H004I24 - Muhammad Ali";
    const int dataSize = strlen(data);
    char buffer[256];
    
    cout << "File Information and Copy Program" << endl;

    // Step 1: Create and write to source.txt
    cout << "Creating or opening source.txt..." << endl;
    hFile = CreateFileA(
        "source.txt",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        cout << "Error creating source.txt" << endl;
        return 1;
    }

    cout << "Writing student data to source.txt..." << endl;
    success = WriteFile(
        hFile,
        data,
        dataSize,
        &bytesWritten,
        NULL
    );

    if (!success) {
        cout << "Error writing to file" << endl;
        CloseHandle(hFile);
        return 1;
    }

    cout << "Closing source.txt after writing..." << endl;
    CloseHandle(hFile);

    // Step 2: Read from source.txt and display content
    cout << "Opening source.txt for reading..." << endl;
    hFile = CreateFileA(
        "source.txt",
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        cout << "Error opening source.txt for reading" << endl;
        return 1;
    }

    cout << "Reading data from source.txt..." << endl;
    success = ReadFile(
        hFile,
        buffer,
        sizeof(buffer) - 1,
        &bytesRead,
        NULL
    );

    if (!success) {
        cout << "Error reading file" << endl;
        CloseHandle(hFile);
        return 1;
    }

    buffer[bytesRead] = '\0';
    cout << "File content: " << buffer << endl;
    cout << "Closing source.txt after reading..." << endl;
    CloseHandle(hFile);

    // Step 3: Copy file to destination.txt
    cout << "Copying source.txt to destination.txt..." << endl;
    success = CopyFileA("source.txt", "destination.txt", FALSE);
    if (!success) {
        cout << "Error copying file" << endl;
        return 1;
    }

    // Step 4: Get and display file information
    cout << "Getting file information..." << endl;
    
    // Get source.txt information
    hFile = CreateFileA("source.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD fileSize = GetFileSize(hFile, NULL);
        cout << "source.txt size: " << fileSize << " bytes" << endl;
        
        DWORD attributes = GetFileAttributesA("source.txt");
        cout << "source.txt attributes: " << attributes << endl;
        
        FILETIME creationTime, lastAccessTime, lastWriteTime;
        GetFileTime(hFile, &creationTime, &lastAccessTime, &lastWriteTime);
        CloseHandle(hFile);
    }

    // Get destination.txt information
    hFile = CreateFileA("destination.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD fileSize = GetFileSize(hFile, NULL);
        cout << "destination.txt size: " << fileSize << " bytes" << endl;
        
        DWORD attributes = GetFileAttributesA("destination.txt");
        cout << "destination.txt attributes: " << attributes << endl;
        
        FILETIME creationTime, lastAccessTime, lastWriteTime;
        GetFileTime(hFile, &creationTime, &lastAccessTime, &lastWriteTime);
        CloseHandle(hFile);
    }

    // Step 5: Get current working directory
    char currentDir[MAX_PATH];
    DWORD dirLength = GetCurrentDirectoryA(MAX_PATH, currentDir);
    if (dirLength > 0) {
        cout << "Current working directory: " << currentDir << endl;
    } else {
        cout << "Error getting current directory" << endl;
    }

    cout << "All tasks completed successfully." << endl;

    return 0;
}