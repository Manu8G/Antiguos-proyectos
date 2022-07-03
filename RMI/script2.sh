#!/bin/bash

javac *.java
ruta=pwd 

java -cp . -Djava.rmi.server.codebase=file:$ruta -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ServerUno &
java -cp . -Djava.rmi.server.codebase=file:$ruta -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ServerDos &
java -cp . -Djava.rmi.server.codebase=file:$ruta -Djava.rmi.server.hostname=localhost -Djava.security.policy=server.policy ServerTres &
sleep 2
java -cp . -Djava.security.policy=server.policy cliente ServerUno
java -cp . -Djava.security.policy=server.policy cliente ServerDos
java -cp . -Djava.security.policy=server.policy cliente ServerTres

kill %1
kill %2
kill %3