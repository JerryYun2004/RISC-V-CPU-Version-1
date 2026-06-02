`timescale 1ns/1ps

// Load/store helper for byte enables, store-data alignment, load extraction,
// sign extension, and misalignment detection.
module lsu (
    input  logic [31:0] addr_i,
    input  logic [31:0] store_data_i,
    input  logic [31:0] load_rdata_i,
    input  logic [2:0]  funct3_i,
    input  logic        is_load_i,
    input  logic        is_store_i,

    output logic [3:0]  be_o,
    output logic [31:0] store_wdata_o,
    output logic [31:0] load_data_o,
    output logic        misaligned_o
);

  logic [7:0]  selected_byte;
  logic [15:0] selected_half;

  always_comb begin
    be_o           = 4'b0000;
    store_wdata_o  = 32'h0000_0000;
    load_data_o    = 32'h0000_0000;
    misaligned_o   = 1'b0;
    selected_byte  = 8'h00;
    selected_half  = 16'h0000;

    // Store byte enables and aligned write data.
    if (is_store_i) begin
      unique case (funct3_i)
        3'b000: begin // SB
          unique case (addr_i[1:0])
            2'b00: begin be_o = 4'b0001; store_wdata_o = {24'h0, store_data_i[7:0]}; end
            2'b01: begin be_o = 4'b0010; store_wdata_o = {16'h0, store_data_i[7:0], 8'h0}; end
            2'b10: begin be_o = 4'b0100; store_wdata_o = {8'h0, store_data_i[7:0], 16'h0}; end
            2'b11: begin be_o = 4'b1000; store_wdata_o = {store_data_i[7:0], 24'h0}; end
            default: begin be_o = 4'b0000; store_wdata_o = 32'h0; end
          endcase
        end

        3'b001: begin // SH
          if (addr_i[0] != 1'b0) begin
            misaligned_o = 1'b1;
          end else if (addr_i[1] == 1'b0) begin
            be_o = 4'b0011;
            store_wdata_o = {16'h0, store_data_i[15:0]};
          end else begin
            be_o = 4'b1100;
            store_wdata_o = {store_data_i[15:0], 16'h0};
          end
        end

        3'b010: begin // SW
          if (addr_i[1:0] != 2'b00) begin
            misaligned_o = 1'b1;
          end else begin
            be_o = 4'b1111;
            store_wdata_o = store_data_i;
          end
        end

        default: begin
          misaligned_o = 1'b1;
        end
      endcase
    end

    // Load extraction and sign/zero extension.
    if (is_load_i) begin
      unique case (addr_i[1:0])
        2'b00: selected_byte = load_rdata_i[7:0];
        2'b01: selected_byte = load_rdata_i[15:8];
        2'b10: selected_byte = load_rdata_i[23:16];
        2'b11: selected_byte = load_rdata_i[31:24];
        default: selected_byte = 8'h00;
      endcase

      selected_half = (addr_i[1] == 1'b0) ? load_rdata_i[15:0] : load_rdata_i[31:16];

      unique case (funct3_i)
        3'b000: load_data_o = {{24{selected_byte[7]}}, selected_byte}; // LB
        3'b001: begin // LH
          if (addr_i[0] != 1'b0) begin
            misaligned_o = 1'b1;
            load_data_o = 32'h0000_0000;
          end else begin
            load_data_o = {{16{selected_half[15]}}, selected_half};
          end
        end
        3'b010: begin // LW
          if (addr_i[1:0] != 2'b00) begin
            misaligned_o = 1'b1;
            load_data_o = 32'h0000_0000;
          end else begin
            load_data_o = load_rdata_i;
          end
        end
        3'b100: load_data_o = {24'h0, selected_byte}; // LBU
        3'b101: begin // LHU
          if (addr_i[0] != 1'b0) begin
            misaligned_o = 1'b1;
            load_data_o = 32'h0000_0000;
          end else begin
            load_data_o = {16'h0, selected_half};
          end
        end
        default: begin
          misaligned_o = 1'b1;
          load_data_o = 32'h0000_0000;
        end
      endcase
    end
  end

endmodule
