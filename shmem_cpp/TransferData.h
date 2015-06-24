#ifndef TRANSFER_DATA_H
#define TRANSFER_DATA_H

#include <iostream>

#define MAX_ENTITIES 30

struct State
{
   double x;
   double y;
   double z;
};

struct Stat
{
   unsigned int numAvailable;
   unsigned int numUsed;
};

struct TransferData
{
   double exLg;
   float other;
   unsigned int more;
   int more2;
   unsigned char next;
   bool statusReady;

   Stat status;
   State entities[MAX_ENTITIES];
};

#define C_OFF 1000
void fill(TransferData* data)
{
   data->exLg = C_OFF + 1.0;
   data->other = C_OFF + 2.0;
   data->more = C_OFF + 3;
   data->more2 = C_OFF + 4;
   data->next = 5;
   data->statusReady = true;
   data->status.numAvailable = C_OFF + 7;
   data->status.numUsed = C_OFF + 8;

   int index = 9;
   for (int i = 0; i < MAX_ENTITIES; i++)
   {
      data->entities[i].x = C_OFF + index++;
      data->entities[i].y = C_OFF + index++;
      data->entities[i].z = C_OFF + index++;
   }
}

void print_entity(TransferData* data, int number)
{
   std::cout << "entities[" << number << "]: " << data->entities[number].x <<
      " " << data->entities[number].y << " " << data->entities[number].z <<
      std::endl;
}

void print(TransferData* data)
{
   std::cout << "exLg: " << data->exLg << std::endl;
   std::cout << "other: " << data->other << std::endl;
   std::cout << "more: " << data->more << std::endl;
   std::cout << "more2: " << data->more2 << std::endl;
   std::cout << "next: " << data->next << std::endl;
   std::cout << "statusReady: " << data->statusReady << std::endl;
   std::cout << "numAvailable: " << data->status.numAvailable << std::endl;
   std::cout << "numUsed: " << data->status.numUsed << std::endl;
   print_entity(data, 0);
   print_entity(data, 1);
   print_entity(data, 15);
   print_entity(data, MAX_ENTITIES - 1);

}


#endif // TRANSFER_DATA_H