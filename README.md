****
# Average File Size Calculator

**Calculates the average file size of files within the provided directory, recursiely.**


*Note: this is a quick and dirty utility.*

****

# Building

**ONLY TESTED ON WINDOWS 64 bit - Any other OS's are not guaranteed to work.**

1) Installing / Setting up QT

    - please note that this will take up a ton of storage space depending on the components you install. (the source code is massive)

        a) Download the QT installer from [this site](https://www.qt.io/download-qt-installer-oss).
        
        b) You may have to create a free account with QT.
        
        c) I reccomend keeping the default installation directory (at C:/Qt)
        
        d) Select "Qt 6.9.1 for desktop development"
        
        e) Finish the installation process. It will take a while!

2) Cloning this project via git

    - Once QT installed, you are ready to clone this project and set up the enivronment!

        a) Open command prompt to your Documents folder, making sure it's NOT your OneDrive Documents (onedrive will attempt to upload everything...) or wherever you keep your projects

        - Note: you must have [git for windows](https://git-scm.com/downloads/win) installed for this next step. 
        - You may skip installing git and directly download and unzip the source code if you wish.
        
        b) Run `git clone https://github.com/PolymorphicAgent/AverageFileSize.git`
        - You should see a new folder named `AverageFileSize' appear in your Documents folder (or wherever you decided to put it) 
        
3) Configuring the environment in QT creator
    - In file explorer, you should be able to right-click open the project file `AverageFileSize.pro` with QT creator, the IDE that integrates best with the QT Framework.
    
        a) Once QT Creator loads, you should be on the "configure project screen". You may use whichever kit you like. I used MinGW 6.9.1, and that worked.

        b) Hit `Configure Project" in the bottom corner.
        
4) Test Build!
    - Once you've got this environment set up:
    
        a) Hit the green play button to run the build process!
        
        b) If it compiles correctly, the utility should pop up!

****
