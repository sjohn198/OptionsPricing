## Usage Instructions:
General:
make all

put_call_parity:
./put_call_parity [mode flag] [mode value] [strike price] [time to maturity] [risk-free interest rate] [initial stock price]

Mode flag is either -p or -c corresponding to which option price you already have. For example, if you have the call price, use the
-c flag and put its value for the mode value argument and you will be given the corresponding put price.

bsm_probabalistic:
./bsm_probabalistic [strike price] [time to maturity] [risk-free interest rate] [initial stock price] [volatility]

May try to implement a method for calculating implied volatility. Until then, this is a toy function