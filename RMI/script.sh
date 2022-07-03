#!/bin/bash

javac *.java
ruta=pwd 
gnome-terminal -- java -cp . -Djava.rmi.server.codebase=file:$ruta -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ServerUno
gnome-terminal -- java -cp . -Djava.rmi.server.codebase=file:$ruta -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ServerDos
gnome-terminal -- java -cp . -Djava.rmi.server.codebase=file:$ruta -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ServerTres

gnome-terminal -- java -cp . -Djava.security.policy=server.policy cliente ServerUno
gnome-terminal -- java -cp . -Djava.security.policy=server.policy cliente ServerDos
gnome-terminal -- java -cp . -Djava.security.policy=server.policy cliente ServerTres
