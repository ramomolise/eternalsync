#!/bin/bash

# Check if the script is run as root

if [ "$EUID" -ne 0 ]; then
   echo "Please run this script as root or with sudo."
    exit 1
fi

# Move to temp folder

mkdir ../temp
cd ../temp

# Update Packages

#apt update && apt upgrade -y
dnf update -y

# Install Nomachine

#wget https://download.nomachine.com/download/8.10/Linux/nomachine_8.10.1_1_amd64.deb
#dpkg -i nomachine*.deb

wget https://download.nomachine.com/download/8.10/Linux/nomachine_8.10.1_1_x86_64.rpm
rpm -i nomachine*.rpm

################################### Generate autostart ###################################

# Get Resoltion details (Varibales: cvt info, xrandr monitor name, resolution name)
# User Input Variables (mobile resolution wanted, xrandr monitor name,resolution name)

# CVT test script 

output=$(cvt 720 1500)
modeline=$(echo "$output" | grep -o 'Modeline "720x1500_.*"') # Need to find a way to get text after Modeline

if [ -n "$modeline" ]; then
echo "$modeline" > modeline_info.txt
echo "Modeline information saved to modeline_info.txt"
else
    echo "Modeline information not found in the 'cvt' output."
fi