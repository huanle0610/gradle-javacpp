## how to run

1. sdk list gradle

```sh
sdk rm gradle 8.0.2
sdk install gradle 7.6

cd samples/zlib
gradle test
```


## use includeBuild

- no includeBuild

```sh
$ gradle buildEnvironment

> Task :buildEnvironment

------------------------------------------------------------
Root project 'zlib'
------------------------------------------------------------

classpath
\--- org.bytedeco.gradle-javacpp-build:org.bytedeco.gradle-javacpp-build.gradle.plugin:1.5.8
     \--- org.bytedeco:gradle-javacpp:1.5.8
          \--- org.bytedeco:javacpp:1.5.8
```
- use includeBuild

```sh
$ gradle buildEnvironment

> Task :buildEnvironment

------------------------------------------------------------
Root project 'zlib'
------------------------------------------------------------

classpath
\--- project :gradle-javacpp
     \--- org.bytedeco:javacpp:1.5.9-SNAPSHOT
```