#include <systemc.h>
#include <fstream> // Thư viện cần thiết để ghi vào tệp VCD

SC_MODULE(IC555) {
    sc_in<bool> clk;
    sc_out<bool> out;

    SC_CTOR(IC555) {
        SC_METHOD(toggle_output);
        sensitive << clk.pos();
    }

    void toggle_output() {
        out.write(!out.read());
    }
};

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> clk_sig;
    sc_signal<bool> out_sig;

    IC555 ic555("IC555");
    ic555.clk(clk_sig);
    ic555.out(out_sig);

    // Khai báo tệp VCD để lưu kết quả
    sc_trace_file *wf = sc_create_vcd_trace_file("output");
    
    // Theo dõi tín hiệu
    sc_trace(wf, clk_sig, "clk");
    sc_trace(wf, out_sig, "out");

    for (int i = 0; i < 10; ++i) {
        clk_sig.write(true);
        sc_start(5, SC_NS);
        clk_sig.write(false);
        sc_start(5, SC_NS);

        std::cout << "Output at step " << i << ": " << out_sig.read() << std::endl;
    }

    // Đóng tệp VCD khi kết thúc mô phỏng
    sc_close_vcd_trace_file(wf);

    return 0;
}
