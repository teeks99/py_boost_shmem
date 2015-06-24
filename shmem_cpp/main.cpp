
#include "TransferData.h"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/windows_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

using namespace boost::interprocess;

int main(int argc, char* argv[]) 
{
   if (argc > 1)
   {
      // Get Data
      windows_shared_memory shmem(open_only, "TransferDataSHMEM", read_write);
      //shared_memory_object shmem(open_only, "PyTransferDataSHMEM", read_write);
      mapped_region region(shmem, read_write);

      TransferData* data = reinterpret_cast<TransferData*>(region.get_address());

      std::cout << "C++ Program - Getting Data" << std::endl;
      print(data);
   }
   else
   {
      // Create Data
      windows_shared_memory shmem(create_only, "TransferDataSHMEM", 
         read_write, sizeof(TransferData));
      //shared_memory_object shmem(open_or_create, "CppTransferDataSHMEM", read_write);
      //shmem.truncate(sizeof(TransferData));
      mapped_region region(shmem, read_write);
      std::memset(region.get_address(), 0, sizeof(TransferData));

      TransferData* data = reinterpret_cast<TransferData*>(region.get_address());

      std::cout << "C++ Program - Filling Data" << std::endl;
      fill(data);
      std::system("pause");
   }
   return 0;
}