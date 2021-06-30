# How to create a conan package

## Into:

- we need to use template

### More information:

- [learn from sdk](./learn_from_sdk.md)

### Example1:

- create source code and test pacakge

```
conan new bf_helper/1.0 -t -s
```

- build and run for test.

```
conan create . user/testing
conan create . user/testing -s build_type=Debug
conan create . user/testing -s build_type=Release
```

#### Multiple Platform Build Target:

- iOS

```
conan create . user/testing -s build_type=Debug --profile ios
conan create . user/testing -s build_type=Debug --profile ios_sim
```

- macOS
- MARK this if needed "compiler.libcxx=libstdc++"

```
CC=clang CXX=clang++ conan create . user/testing -s build_type=Debug --profile macOS --build=missing
```

#### Android Build 之前，要安裝 NDK

```
conan create . user/testing -s build_type=Debug --profile android-armv7
conan create . user/testing -s build_type=Debug --profile android-armv8
```

### Issues:

- want to use template, don't know where to download.

#### Example:(v1.36)

```
conan new bf_helper/1.0 --template=myconanfile.py
conan new bf_header/1.0 --template=header_only
```
