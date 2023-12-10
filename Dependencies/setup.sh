#!/bin/bash

echo "Installing Dependencies"
sleep 2


dependencies() {

   #Distributed detect
   if [ -f /etc/debian_version ]; then
	
      #C installing Dependencies
      sudo apt update 
      sudo apt install libssl-dev -y
      sudo apt install libcurl-dev -y
      sudo apt install libcurl4-openssl-dev -y
      sudo apt install libpcap-dev -y
      sudo apt install zlib1g-dev -y
   
      sleep 1
   
      #Python installing Dependencies
      sudo pip install python-time
      sudo pip install hashlib
      sudo pip install os-sys
      sudo pip install multiprocessing
      sudo pip install zlib


   elif [ -f /etc/arch-release  ]; then
   
      #C installing Dependencies
      sudo pacman -Sy
      sudo pacman -S --noconfirm libcurl-dev libssl-dev libcurl4-openssl-dev -y
      sudo pacman -S mingw-w64-x86_64-zlib -y
      sudo pacman -S libpcap -y

   
      sleep 1
   
      #Python installing Dependencies
      sudo pip install python-time
      sudo pip install hashlib
      sudo pip install os-sys
      sudo pip install multiprocessing
      sudo pip install zlib
   
   
   elif [ -f /etc/redhat-release ]; then
   
      #C installing Dependencies
      sudo dnf makecache
      sudo dnf install -y libcurl-dev libssl-dev  libcurl4-opessl-dev
      sudo dnf install zlib-devel
      sudo dnf install libpcap-devel

   
      #Python installing Dependencies
      sudo pip install python-time
      sudo pip install hashlib
      sudo pip install os-sys
      sudo pip install multiprocessing
      sudo pip install zlib
   
   fi

}


trap 'echo "An error occurred. The transaction is ending."; exit 1' ERR

#call function
dependencies

echo "Dependencies installed successfully"
