import yfinance as yf
import streamlit as st
import datetime

st.write("""
# Simple Stock Price App
Shown are the stock **closing price** and ***volume*** of Company!
""")


st.sidebar.header('User Input')

#define the ticker symbol
tickerSymbol = st.sidebar.selectbox ('Company',('GOOGL','AAPL','MSFT','NSE','HONAUT'))
st.sidebar.text("")
time = st.sidebar.selectbox('Period',('1h','1d','1wk','1mo','5mo'))

today = datetime.date.today()
start_date = st.sidebar.date_input('Start date', datetime.date(2010,5,30))
end_date = st.sidebar.date_input('End date', today)
if start_date < end_date:
    st.sidebar.success('Start date: `%s`\n\nEnd date:`%s`' % (start_date, end_date))
else:
    st.sidebar.error('Error: End date must fall after start date.')

#get data on this ticker
tickerData = yf.Ticker(tickerSymbol)
#get the historical prices for this ticker
tickerDf = tickerData.history(period = time, start = start_date, end = end_date)
# Open	High	Low	Close	Volume	Dividends	Stock Splits

st.write("""
## Closing Price
""")
st.line_chart(tickerDf.Close)
st.write("""
## Volume Price
""")
st.line_chart(tickerDf.Volume)