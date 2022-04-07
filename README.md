# Embedded Rings

## Introduction

TIME: ~ 2.5hr

WRITTEN BY: [ETIENNE NAUDE](https://etinaude.dev)

LINK: [https://github.com/etinaude/embedded-demo](https://github.com/etinaude/embedded-demo)

<!-- TODO ADD SOME IMAGES HERE MAYBE A GIF -->

## Step 1: Code

The first step is to download the code for this project which you can do from here

[https://github.com/etinaude/embedded-demo](https://github.com/etinaude/embedded-demo)

you should find these instructions in the README.md file.

## Step 2: Get Software

This project use arduino which requires the arduino IDE to run, I recommend using [Arduino IDE 2.0 RC](https://www.arduino.cc/en/software#future-version-of-the-arduino-ide), but platform IO or Arduino version 1 are also supported.

## Step 3: Hardware

During the in person workshop we will provide you with a few components, these are:

- 1 - [D1 mini ESP8266 dev board](https://www.aliexpress.com/item/1005001621784437.html?spm=a2g0o.order_list.0.0.21ef1802m8rokq)
- 0.5m - [60led/m 5050 addressable LEDs](https://www.aliexpress.com/item/1005001345392567.html?spm=a2g0o.order_list.0.0.21ef1802m8rokq)
- 6 - Jumper wires
- 1 - [3D printed ring](<!-- TODO Add link to model and print settings -->)
- 1 - [Lasercut 200gsm Card](<!-- TODO Add link to design -->)

You will need to bring 2 things

- A laptop with an internet connection and USB ports
- A micro USB cable

### Step 3.1: Finishing the model

Glue the paper using some super glue to the top of the 3d printed ring as shown below, try center it as much as possible.

![construction!](/images/construct.jpg)

### Step 3.2: Wiring

Wire the LEDS to the D1.

Inside ring (short LEDs):

- +5V -> VIN
- GND -> GND
- DIN -> D0

Outside ring (Long LEDs):

- +5V -> VIN
- GND -> GND
- DIN -> D1

![diagram!](/images/digram.png)

## Step 4: Configuration

### Step 4.1: WIFI

We will use [Sinric Pro](https://sinric.pro/index.html) to connect this to the internet and to [Google Assistant](https://assistant.google.com/)

Start by creating a [free Sinric Pro account](https://portal.sinric.pro/register).

then create a new light by clicking on devices and **+ Add Device**.

then fill in a name for your circle and select **Smart Light Bulb** for the Device Type.

Then click next until you are on the screen which shows the details of your device. It should look like this:

![diagram!](/images/sinricDeviceSetp.png)

### Step 4.2: Configuration File

Open the demo code in the Arduino IDE

copy paste each field into the **config.h** and add your WIFI details (SSID and password)

### Step 4.3: Pattern

In the config file select a pattern by uncommenting (removing the `//`) the pattern you would like. The pattern options are at the end of this document.

## Step 5: Upload Demo Code

Plug the D1 into your laptop and

Select the board from the drop down menu. then click the upload button (right pointing arrow).

This should now show the pattern you selected

## Optional Steps

### Google Assistant

You can add a connection to Google Assistant via the sinric pro app. Download the app from the [Google Play Store](https://play.google.com/store/apps/details?id=pro.sinric&hl=en_NZ&gl=US) or the [Apple App Store](https://apps.apple.com/us/app/sinric-pro/id1513086098). From the app you log in and all your devices should display in a list. Then you can open the [Google Home](https://play.google.com/store/apps/details?id=com.google.android.apps.chromecast.app&hl=en_NZ&gl=US) app

### Custom Patterns

There are many other pattern options make with this, each LED can take a few different colours (about 16 million) but most would look too similar to each other to see, I would recommend using bright colours that are highly saturated.

### API Connections?

Many companies such as Facebook, Google, Canvas, Discord etc. Have APIs which allow you to link into their services. This means you can potentially have your lights react to certain events. For Example your lights can show green if you received a good grade on canvas and red if you received a bad grade.

I have not used all of these APIs so I am not sure the exact access you have or how to set them up but this is an example of the kinds of things you can do. And this is outside the scope of this workshop

## Other things you can make with this

Automated front door lock\
Automated garage door lock\
Automated switch (eg put in on a fan)\
Automating Air con\
Collect data from sensors\
Security System\
Mini webserver\
Automating 3D printers\
Decor of various sorts

## Simulator

![lights!](/images/sim.png)

Here is a link to a simplified demonstration of the lights working.

[https://wokwi.com/projects/328281603421766226](https://wokwi.com/projects/328281603421766226)

## Pattern Options

![lights!](/images/lights.jpg)
