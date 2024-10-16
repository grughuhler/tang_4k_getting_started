module top (
   input wire clk,
   input wire reset_button,
   output wire uart0_txd,
   input wire uart0_rxd,
   inout wire led,
   inout wire button1
);
   wire [13:0] unused; /* using this quiets signal unconnected warnings */

	Gowin_EMPU_Top your_instance_name(
		.sys_clk(clk), //input sys_clk
		.gpio({unused, button1, led}), //inout [15:0] gpio
		.uart0_rxd(uart0_rxd), //input uart0_rxd
		.uart0_txd(uart0_txd), //output uart0_txd
		.reset_n(reset_button) //input reset_n
	);
endmodule