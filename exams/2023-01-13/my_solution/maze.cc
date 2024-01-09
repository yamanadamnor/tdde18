#include <set>
#include <iostream>

struct Room
{
    Room* north;
    Room* east;
    Room* south;
    Room* west;
};

class Maze
{
public:
    Maze(Room* entrance) : entrance{entrance} {}

    ~Maze() {
        std::set<Room*> visited{};
        deleteRooms(entrance, visited);
    }

    void deleteRooms(Room *curr, std::set<Room*> &visited) {
        if (curr->north != nullptr && visited.count(curr->north) == 0) {
            visited.insert(curr);
            deleteRooms(curr->north, visited);
        }
        if (curr->east != nullptr && visited.count(curr->east) == 0) {
            visited.insert(curr);
            deleteRooms(curr->east, visited);
        }
        if (curr->south != nullptr && visited.count(curr->south) == 0) {
            visited.insert(curr);
            deleteRooms(curr->south, visited);
        }
        if (curr->west != nullptr && visited.count(curr->west) == 0) {
            visited.insert(curr);
            deleteRooms(curr->west, visited);
        }

        visited.insert(curr);
        delete curr;
    }

    /* Everything but the destructor is given
       (except any includes needed for the destructor) */
    
    Maze(Maze const& other) = delete;
    Maze(Maze && other) = delete;    
    Maze operator=(Maze const& other) = delete;
    Maze operator=(Maze && other) = delete;
    
private:
    Room* entrance;

};

Room* setup_rooms()
{
    Room* r1{ new Room{} };
    Room* r2{ new Room{} };
    Room* r3{ new Room{} };
    Room* r4{ new Room{} };
    Room* r5{ new Room{} };
    Room* r6{ new Room{} };

    r1->east=r2;  r1->south=r4;
    r2->east=r3;  r2->south=r5; r2->west=r1;
    r3->south=r6; r3->west=r2;
    r4->north=r1; r4->east=r5;
    r5->north=r2; r5->west=r4;
    r6->north=r3;
    return r1;
}

int main()
{
    Maze maze{setup_rooms()};
}

