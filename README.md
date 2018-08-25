# Yaoshi

Yaoshi (钥匙) mean "key" in chinese.

Yaoshi aims to build a hardware replacement of softwares like Keepass.


# Testing

There are complete programs under `itest` folder.
Their main purpose are to test small parts of the hardware.

I wish to use the `platformio test` feature, but I need to pay $12/month, which is way too expensive to run tests locally I think.
So I made a new project in each of the directory under `itest`.

For instance, to test the built in led :
```
cd itest/blink
platformio run -t clean
platformio run
platformio run -t upload
```
The LED should be blinking