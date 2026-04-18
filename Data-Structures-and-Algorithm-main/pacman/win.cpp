// Assignment 1 - FileInfoCopy - CS609 - Fall 2025

#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;

void printError(const string& operation) {
    DWORD error = GetLastError();
    cout << "Error in " << operation << ". Error code: " << error << endl;
}

void printFileTime(const FILETIME& ft, const string& label) {
    SYSTEMTIME st;
    FileTimeToSystemTime(&ft, &st);
    cout << label << ": " << st.wYear << "-" 
         << setw(2) << setfill('0') << st.wMonth << "-"
         << setw(2) << setfill('0') << st.wDay << " "
         << setw(2) << setfill('0') << st.wHour << ":"
         << setw(2) << setfill('0') << st.wMinute << ":"
         << setw(2) << setfill('0') << st.wSecond << endl;
}

int main() {
    HANDLE hFile;
    DWORD bytesWritten, bytesRead;
    BOOL success;
    const char* data = "BC020H004I24 - Muhammad Ali";
    const int dataSize = strlen(data);
    char buffer[256];
    
    cout << "File Information and Copy Program" << endl;
    cout << "=================================" << endl << endl;

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
        printError("CreateFile (source.txt)");
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
        printError("WriteFile");
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
        printError("CreateFile (read source.txt)");
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
        printError("ReadFile");
        CloseHandle(hFile);
        return 1;
    }

    buffer[bytesRead] = '\0'; // Null-terminate the string
    cout << "File content: " << buffer << endl;
    cout << "Closing source.txt after reading..." << endl;
    CloseHandle(hFile);

    // Step 3: Copy file to destination.txt
    cout << "Copying source.txt to destination.txt..." << endl;
    success = CopyFileA("source.txt", "destination.txt", FALSE);
    if (!success) {
        printError("CopyFile");
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
        if (GetFileTime(hFile, &creationTime, &lastAccessTime, &lastWriteTime)) {
            printFileTime(creationTime, "source.txt creation time");
            printFileTime(lastWriteTime, "source.txt last write time");
        }
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
        if (GetFileTime(hFile, &creationTime, &lastAccessTime, &lastWriteTime)) {
            printFileTime(creationTime, "destination.txt creation time");
            printFileTime(lastWriteTime, "destination.txt last write time");
        }
        CloseHandle(hFile);
    }

    // Step 5: Get current working directory
    char currentDir[MAX_PATH];
    DWORD dirLength = GetCurrentDirectoryA(MAX_PATH, currentDir);
    if (dirLength > 0) {
        cout << "Current working directory: " << currentDir << endl;
    } else {
        printError("GetCurrentDirectory");
    }

    cout << endl << "All tasks completed successfully." << endl;
    cout << "=================================" << endl;

    return 0;
}