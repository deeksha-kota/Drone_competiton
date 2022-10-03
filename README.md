# isae-group-drone

Welcome to the ISAE Group Drone Competition MATLAB port code repo!

This code is a MATLAB interface (with a C/C++ computer vision module) for the physical Tello drone or a simulated one for experimental purposes. The simuled drone binary executable is available for Windows, Linux, and Mac on the following links:

- [Windows](https://estaca-my.sharepoint.com/:u:/g/personal/fouad_khenfri_estaca_fr/EQUqxDKFm01Bgi1i04W7gbsBgY24RVqwS-NgVR3zH9KE6Q?e=aSyMXR)

- [MacOS](https://estaca-my.sharepoint.com/:u:/g/personal/fouad_khenfri_estaca_fr/ESWV_3cBTsZHsm-PDOOgidoBOi0ZS2kYqM5I5PHfCQKgBQ?e=XotghL)

- [Linux](https://estaca-my.sharepoint.com/:u:/g/personal/fouad_khenfri_estaca_fr/ESsUey-ZAPJPuXkKviXmEXkB5J99t-F6SCLPO1kGDUP8IA?e=Lw7TZj)

In the competition day, you will have access to a real Tello drone, and this repository code provides libraries that transparently connect MATLAB to either simulated or real Tellos. That said, you will use the same code in your simulations and in the competition day.

## How to get this code running

Start by cloning this repository.

```
git clone https://gitlab.isae-supaero.fr/l.ribeiro-lustosa/isae-group-drone.git
```

Compile the computer vision module. For that, you will need the OpenCV libraries in your system. Please check https://opencv.org/ for downloading and installing instructions. In Linux:

```
cd isae-group-drone
mkdir build
cd build
cmake ..
make
```

This yields a **tello-vision** executable that contains the computer vision module of the competition. Since MATLAB provides poor access to OpenCV libraries, we've provided to you a separate computer vision module that will communicate with MATLAB through UDP sockets. Please feel free to modify and recompile this code to optimize your race time!

After compilation, you can execute the binary Tello simulator. However, if it is the first time executing it after downloading it, you might need to add executable access to the recently downloaded **Tello_Simulator.x86_64** file:

```
chmod +x Tello_Simulator.x86_64
./Tello_Simulator.x86_64
```

After the simulator is up and running, you can execute in MATLAB the Tello init script **tello_takeoff.m** for configuring its takeoff and video streaming. Finally, you can run the **tello.slx** file in Simulink, which is the main control and telemetry link for the Tello, and where you will code most of your control actions in MATLAB.

Good luck!

## The Python Version

In case you prefer to use Python instead of MATLAB, you can disregard this repo and download instead the respective files in the following link:

https://estaca-my.sharepoint.com/personal/fouad_khenfri_estaca_fr/_layouts/15/onedrive.aspx?id=%2Fpersonal%2Ffouad%5Fkhenfri%5Festaca%5Ffr%2FDocuments%2FCHALLENGE%20DRONE%20ISAE%2FDrone%20Racing%20Code%2Ezip&parent=%2Fpersonal%2Ffouad%5Fkhenfri%5Festaca%5Ffr%2FDocuments%2FCHALLENGE%20DRONE%20ISAE&ga=1

## Any other language? (Advanced)

In case you want to use other language other than MATLAB or Python, the Tello drone/simulator communicate through UDP sockets, which are platform independent, and therefore, programmable and highly customizable. You can develop your own UDP solution by going through the Tello SDK API documentation and our code examples (in MATLAB or Python).

# Trouble?

If you encounter problems, do not hesitate to leave an entry at our repo **Issues** section, or contact the competition organizers at your school.
