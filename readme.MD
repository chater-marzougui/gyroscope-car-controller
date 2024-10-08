<a name="readme-top"></a>
<div align="center">

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]](https://www.linkedin.com/in/chater-marzougui-342125299/)
</div>


<!-- PROJECT LOGO -->
<br />
<div align="center">
    <h1 style="font-size:35px">ESP8266 WebSocket Car Control</h1>
    <br>
    <p style="font-size:20px" align="center">
        A project to control a car using an ESP8266 and WebSocket communication
    <br>
    <br>
    <a href="https://github.com/chater-marzougui/gyroscope-car-controller/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/chater-marzougui/gyroscope-car-controller/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
  <br><br>
  <!-- <a href="https://github.com/chater-marzougui/gyroscope-car-controller">
    <img src="https://github.com/chater-marzougui/gyroscope-car-controller/assets/images/project-image.png" alt="Project Image" width="70%">
  </a> -->
</div>


# ESP8266 WebSocket Car Control
<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a></li>
    <li><a href="#features">Features</a></li>
    <li><a href="#installation">Installation</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project
This project demonstrates how to control a car wirelessly using two ESP8266 modules. The first ESP8266 serves as a WebSocket server receiving steering commands, while the second one, connected to an MPU6050 gyroscope, acts as a client sending rotation data. The gyroscope is rotated to steer the car.

### Required Materials
- 2 x ESP8266 or ESP32
- 1 x MPU: GY-521 or a better accelerometer module
- 2 x N20 Motors (or 4)
- 1 x MotorDriver L298N
- 3 x 18650 Cells (one for the sender, two for the receiver)

## Features
- **Real-time Control:** Uses WebSocket for low-latency communication between the ESP8266 modules.
- **Wireless Communication:** Establishes a wireless connection without an external router.
- **MPU6050 Integration:** Captures rotation data for steering based on gyroscope orientation.
- **Arduino IDE Compatible:** Developed and tested with the Arduino IDE.

<br/>
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Installation

1. **Clone this repository** to your local machine.
2. **Upload the appropriate sketch** (`Sender` or `Receiver`) to the respective ESP8266 modules.
3. **Connect the hardware** according to the provided pin configuration.
4. **Power the modules** and connect to the Wi-Fi AP created by the receiver.
5. **Test the car control** by rotating the gyroscope module.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement". Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Chater Marzougui - [@Chater-marzougui][linkedin-url] - chater.mrezgui2002@gmail.com <br/>
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/chater-marzougui/gyroscope-car-controller.svg?style=for-the-badge
[contributors-url]: https://github.com/chater-marzougui/gyroscope-car-controller/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/chater-marzougui/gyroscope-car-controller.svg?style=for-the-badge
[forks-url]: https://github.com/chater-marzougui/gyroscope-car-controller/network/members
[stars-shield]: https://img.shields.io/github/stars/chater-marzougui/gyroscope-car-controller.svg?style=for-the-badge
[stars-url]: https://github.com/chater-marzougui/gyroscope-car-controller/stargazers
[issues-shield]: https://img.shields.io/github/issues/chater-marzougui/gyroscope-car-controller.svg?style=for-the-badge
[issues-url]: https://github.com/chater-marzougui/gyroscope-car-controller/issues
[license-shield]: https://img.shields.io/github/license/chater-marzougui/gyroscope-car-controller.svg?style=for-the-badge
[license-url]: https://github.com/chater-marzougui/gyroscope-car-controller/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/chater-marzougui-342125299
