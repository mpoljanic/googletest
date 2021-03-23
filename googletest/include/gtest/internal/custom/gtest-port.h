// Copyright 2015, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Injection point for custom user configurations. See README for details
//
// ** Custom implementation starts here **

#ifndef GOOGLETEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_
#define GOOGLETEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_

#include <cstddef>
#include <cstdio>

extern "C" char *strdup(const char *s) {
    return nullptr;
}

extern "C" char *_strdup(const char *s) {
    return nullptr;
}

int fileno(FILE *stream)
{
  return 0;
}

int isatty(int a)
{
  return 0;
}

int rmdir(const char *path)
{
  return 0;
}

int chdir(const char *path)
{
  return 0;
}

FILE *fdopen(int fd, const char *mode)
{
  return nullptr;
}

// This stub function is required by _mainCRTSturtup
extern "C" void exit(int status)
{
    static_cast<void>(status);
    while (true) {}
}

// This stub function is required by stdlib
extern "C" void _exit()
{
    exit(-1);
}

// This heap allocation stub is required by stdlib
extern "C" unsigned _sbrk(int inc)
{
    static_cast<void>(inc);
    return 0; // The application is not intended to be executed, no need for actual heap.
}

// This stub function is required by stdlib
extern "C" int _kill(int pid, int sig)
{
    static_cast<void>(pid);
    static_cast<void>(sig);
    return -1;
}

// This stub function is required by stdlib
extern "C" int _getpid(void) {
    return 1;
}

// This stub function is required by stdlib
extern "C" int _write(int file, char *ptr, int len)
{
    static_cast<void>(file);
    static_cast<void>(ptr);
    return len;
}

// This stub function is required by stdlib
extern "C" int _read(int file, char *ptr, int len)
{
    static_cast<void>(file);
    static_cast<void>(ptr);
    static_cast<void>(len);
    return 0;
}

// This stub function is required by stdlib
extern "C" int _close(int file)
{
    static_cast<void>(file);
    return -1;
}

// This stub function is required by stdlib
extern "C" int _open(const char *name, int flags, int mode)
{
    static_cast<void>(name);
    static_cast<void>(flags);
    static_cast<void>(mode);
    return -1;
}

// This stub function is required by stdlib
extern "C" int _fstat(int file, struct stat *st)
{
    static_cast<void>(file);
    static_cast<void>(st);
    return -1;
}

// This stub function is required by stdlib
extern "C" int _isatty(int file)
{
    static_cast<void>(file);
    return 1;
}

// This stub function is required by stdlib
extern "C" int _lseek(int file, int ptr, int dir)
{
    static_cast<void>(file);
    static_cast<void>(ptr);
    static_cast<void>(dir);
    return 0;
}

#endif  // GOOGLETEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_
