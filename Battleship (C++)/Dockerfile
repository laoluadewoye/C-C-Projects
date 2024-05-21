FROM gcc:latest
WORKDIR /usr/src/app
COPY . .
RUN g++ -o Battleship.exe main.cpp grid.cpp location.cpp ship.cpp player.cpp computer.cpp battleship.cpp
CMD ["./Battleship.exe"]
