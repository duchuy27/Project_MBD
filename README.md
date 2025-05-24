# 🚀 Project MBD – SystemC Simulation

Dự án này là một ví dụ mô phỏng SystemC trong môi trường Model-Based Design (MBD).

## 📦 Yêu cầu môi trường

Trước khi build và chạy project, bạn cần cài đặt các thành phần sau:

### ✅ Bước 1: Cài đặt các gói cần thiết

#### Trên Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential git cmake libsystemc-dev
```

📌 Nếu bạn chưa có SystemC, bạn có thể biên dịch từ mã nguồn:

```bash
wget https://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz
tar -xvzf systemc-2.3.3.tar.gz
cd systemc-2.3.3
mkdir build
cd build
../configure
make -j$(nproc)
sudo make install
```

#### Trên Windows (WSL hoặc MinGW):
Cài đặt WSL hoặc MinGW
Biên dịch SystemC tương tự như hướng dẫn cho Linux

🛠️ Build Project

```bash
cd /duong_dan_den_thu_muc_du_an
mkdir build
cd build
cmake ..
make
```

📁 Cấu trúc thư mục:

```css
Project/
├── src/
│   └── main.cpp
├── include/
│   └── ...
├── CMakeLists.txt
└── build/        # sinh ra sau khi build
```
▶️ Chạy chương trình
Sau khi build thành công, chạy ứng dụng bằng:

```bash
./build/ten_file_output
(Tùy vào tên file bạn build ra từ main.cpp)
```

📃 Ghi chú thêm
Đảm bảo bạn đã thiết lập biến môi trường SYSTEMC_HOME nếu dùng CMake.

Nếu có thư viện ngoài (ví dụ: ASCON, LoRa...), cần cập nhật CMakeLists.txt cho phù hợp.

📈 Xem tín hiệu mô phỏng (waveform)
File wave.vcd sẽ được tạo trong quá trình chạy mô phỏng nếu bạn dùng sc_trace.

▶️ Mở file .vcd bằng GTKWave:

```bash
gtkwave wave.vcd
```
Nếu bạn đang dùng Windows, có thể mở trực tiếp bằng phần mềm GTKWave đã cài từ: http://gtkwave.sourceforge.net/