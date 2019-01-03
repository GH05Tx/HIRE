cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
src/client.cpp
        
include/client.h
        
src/address.cpp
        
include/address.h
        
src/vehicle.cpp
        
include/vehicle.h
        
src/rent.cpp
        
include/rent.h
        
src/motorvehicle.cpp
        
include/motorvehicle.h
        
src/bicycle.cpp
        
include/bicycle.h
        
src/car.cpp
        
include/car.h
        
src/moped.cpp
        
include/moped.h
        
src/CurrentRentsRepository.cpp
        
include/CurrentRentsRepository.h
        
src/motorvehicle.cpp
       
src/VehicleRepository.cpp
       
include/VehicleRepository.h
        
src/ClientRepository.cpp
     
include/ClientRepository.h
     
src/RentsManager.cpp
    
include/RentsManager.h
    
src/GoldClient.cpp
       
include/GoldClient.h
      
src/BronzeClient.cpp
      
include/BronzeClient.h
    
src/SilverClient.cpp
       
include/SilverClient.h
      
src/BaseClient.cpp
      
include/BaseClient.h
      
src/ClientType.cpp
      
include/ClientType.h
        src/ClientException.cpp include/ClientException.h src/VehicleException.cpp include/VehicleException.h src/RentException.cpp include/RentException.h src/Repository.cpp include/Repository.h)

add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

