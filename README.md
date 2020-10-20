# FunWithCpp
#C++20 #Gtk3 #Gtkmm #Meson #Linux #gnome-builder #multiplatform

A playful project for some interesting experiments in C++ 20 and Gtk 3 in a Meson-based compilation environment. 

C++ has gone a long way since I was writing Microsoft Windows MFC application in the language. Smart pointers, type inference with auto and decltype, coroutines to simulate multi-threading in a thread-safe memory context and a lot more.

This project is very much a testbed for experimenting with all the new features of the C++ language in its "20" edition and uses a pretty simple Gtk 3 application acting as console to make the overall experience of playing with the new features of the language a little less boring than using terminal.

The project's build system is written around Meson and Ninja instead than the usual Make, preferred enviroment for running code is a modern Linux distro but it's perfectly compatible with Microsoft Windows and Apple MacOS given the required libraries listed in the Meson .json dependencies file org.example.App.json
