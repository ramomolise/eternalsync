# EternalSync for Linux

Welcome to the EternalSync project! This set of modifications (mods) is designed to enhance your remote desktop viewing experience on Linux, particularly for mobile devices. EternalSync focuses on creating a seamless synchronization experience with custom display resolutions based on the capabilities of individual devices.

## Getting Started

To get started with EternalSync on your Linux system, follow these steps:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/ramomolise/eternalsync.git
   ```
2. **Modify Display Resolution (Optional):**

    If you want to set custom resolutions, you can do so by editing the 'generator.cpp' file located at 'eternalsync/src/vm/bin/generator.cpp'. Find the relevant section and add a custom resolution, for example:

    For a landscape resolution (e.g., 1280x800), add:

    ```bash
    cvt 1280 800
    ```

    For a portrait resolution (e.g., 800x1280), add:

    ```bash
    cvt 800 1280
    ```

3. **Navigate to the 'vm' Directory:**

    ```bash
    cd eternalsync/src/vm
    ```
4. **Make the 'generateMod.sh' Script Executable:**

    ```bash
    chmod +x generateMod.sh
    ```
5. **Generate the Mod:**

    ```bash
    ./generateMod.sh
    ```

6. **Run 'autoStart.sh' (Optional):**

To apply the custom resolution changes, you can run the 'autoStart.sh' script, or you can manually set 'autoStart.sh' to run on system startup. The 'autoStart.sh' script will ensure that your custom resolution is used for remote desktop viewing.

And that's it! You now have EternalSync set up on your Linux system with custom resolution options. Enjoy an improved remote viewing experience on your mobile device.

## License
EternalSync is licensed under the GNU General Public License version 3.0 (GPL-3.0). Please see the LICENSE file for details.

## Contact
If you encounter any issues or have suggestions, please feel free to open an issue on the project's GitHub repository. Your feedback is valuable!

Thank you for using EternalSync. We hope it enhances your remote desktop viewing experience.

Ramo Molise