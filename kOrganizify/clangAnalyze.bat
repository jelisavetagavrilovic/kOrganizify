@echo off
for /r %%i in (*.cpp *.h) do (
    clang-check -analyze "%%i"
) >> output.log 2>&1

@echo off
for /r %%i in (*.plist) do (
    echo Deleting "%%i"
    del "%%i"
)

