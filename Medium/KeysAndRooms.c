void openOneByOne(int label, int* isrul, int** rooms, int roomsSize, int* roomsColSize)  // isropen = is room unlocked
{
    if (isrul[label] == 1)
        return;

    isrul[label] = 1;

    for (int i = 0; i < roomsColSize[label]; i++)
        openOneByOne(rooms[label][i], isrul, rooms, roomsSize, roomsColSize);

    return;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) 
{
    int* isrul = calloc(roomsSize, sizeof(int));

    openOneByOne(0, isrul, rooms, roomsSize, roomsColSize);

    for (int i = 0; i < roomsSize; i++)
        if (isrul[i] == 0)
            return false;
    
    return true;
}
