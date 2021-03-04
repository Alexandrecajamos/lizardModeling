
#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T13:00:43
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_OpenGL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    octrees.cpp \
    scene.cpp \
    addcube.cpp \
    point.cpp \
    colorrgb.cpp \
    removeobjects.cpp \
    transformobj.cpp \
    sphere.cpp \
    addsphere.cpp \
    transformations.cpp \
    primitive.cpp \
    addbox.cpp \
    addcone.cpp \
    cube2.cpp \
    cube.cpp \
    octreenode.cpp \
    octree.cpp \
    octreeviewoptions.cpp \
    face.cpp \
    edge.cpp \
    mesh.cpp \
    vec2.cpp \
    addcylinder.cpp \
    addmesh.cpp \
    sceneoptions.cpp \
    raycasting.cpp \
    camera.cpp \
    observer.cpp \
    csgnode.cpp \
    createcsg.cpp \
    primitivetocsg.cpp \
    material.cpp \
    light.cpp \
    spotlight.cpp \
    intersection.cpp \
    csgoptions.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    octrees.h \
    scene.h \
    addcube.h \
    point.h \
    colorrgb.h \
    removeobjects.h \
    transformobj.h \
    sphere.h \
    addsphere.h \
    transformations.h \
    primitive.h \
    addbox.h \
    addcone.h \
    cube2.h \
    cube.h \
    octreenode.h \
    octree.h \
    octreeviewoptions.h \
    face.h \
    edge.h \
    mesh.h \
    vec2.h \
    addcylinder.h \
    addmesh.h \
    sceneoptions.h \
    raycasting.h \
    camera.h \
    observer.h \
    csgnode.h \
    createcsg.h \
    primitivetocsg.h \
    material.h \
    light.h \
    spotlight.h \
    intersection.h \
    csgoptions.h

FORMS    += mainwindow.ui \
    octrees.ui \
    addcube.ui \
    removeobjects.ui \
    transformobj.ui \
    addsphere.ui \
    addsphere.ui \
    addbox.ui \
    addcone.ui \
    octreeviewoptions.ui \
    addcylinder.ui \
    addmesh.ui \
    sceneoptions.ui \
    raycasting.ui \
    createcsg.ui \
    primitivetocsg.ui \
    csgoptions.ui

LIBS += -lglut -lGLU
