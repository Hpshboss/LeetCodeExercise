#define max(a, b) a > b ? a : b

bool isObstacle(int* pos, int* dest, int* obstacle) {
    if (pos[0] == obstacle[0] && dest[0] == obstacle[0])
    {
        if (obstacle[1] <= dest[1] && obstacle[1] > pos[1]) return true;
        if (obstacle[1] >= dest[1] && obstacle[1] < pos[1]) return true;
    }
    if (pos[1] == obstacle[1] && dest[1] == obstacle[1])
    {
        if (obstacle[0] <= dest[0] && obstacle[0] > pos[0]) return true;
        if (obstacle[0] >= dest[0] && obstacle[0] < pos[0]) return true;
    }
    return false;
}

int powInt(int base, int exponent) {
    int ret = 1;
    for (int i = 0; i < exponent; i++)
    {
        ret *= base;
    }
    return ret;
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    int ret = 0;
    int pos[2] = {0, 0};
    int dest[2] = {0, 0};
    int direction = 1;

    for (int i = 0; i < commandsSize; i++)
    {
        if (commands[i] == -1)
        {
            direction -= 1;
            continue;
        }
        if (commands[i] == -2)
        {
            direction += 1;
            continue;
        }

        dest[0] = pos[0] + commands[i] * (direction % 2 == 0 ? 1 : 0);
        dest[1] = pos[1] + commands[i] * (direction % 2 == 1 ? 1 : 0);

        for (int j = 0; j < obstaclesSize; j++)
        {
            if (isObstacle(pos, dest, obstacles[j]))
            {
                dest[0] = obstacles[j][0] - (direction % 2 == 0 ? 1 : 0);
                dest[1] = obstacles[j][1] - (direction % 2 == 1 ? 1 : 0);
                break;
            }
        }
        pos[0] = dest[0];
        pos[1] = dest[1];
        ret = max(ret, powInt(pos[0], 2) + powInt(pos[1], 2));
    }

    return ret;
}
