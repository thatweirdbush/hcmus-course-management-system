QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CourseClass.cpp \
    Database.cpp \
    ScoreboardClass.cpp \
    SemesterClass.cpp \
    StaffClass.cpp \
    changePassword.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AccountClass.h \
    AccountManagerClass.h \
    CourseClass.h \
    Database.h \
    DateClass.h \
    Map.h \
    ScoreboardClass.h \
    SemesterClass.h \
    Set.h \
    StaffClass.h \
    StudentClass.h \
    Vector.h \
    changePassword.h \
    mainwindow.h

FORMS += \
    changePassword.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/app-logo.ico \
    assets/blue-gradient-xswap.png \
    assets/blue-gradient-yswap.png \
    assets/blue-gradient.png \
    assets/calendar-icon.png \
    assets/class-icon.png \
    assets/course-icon.png \
    assets/hcmus-logo.png \
    assets/scoreboard-icon.png \
    course.txt \
    data/account.csv \
    data/course.csv \
    data/scoreboard.csv \
    data/semester.csv \
    data/staff.csv \
    data/student.csv

RESOURCES += \
    resource.qrc
