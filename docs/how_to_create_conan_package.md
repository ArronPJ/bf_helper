# How to create a conan package

## Note:

- we need to use template

#### Example1:

```
conan new bf_helper/1.0 -t -s
conan create . user/testing
```

### Issues:

- want to use template, don't know where to download.

#### Example:(v1.36)

```
conan new bf_helper/1.0 --template=myconanfile.py
conan new bf_header/1.0 --template=header_only
```
