 # Overview #
 <p> The aim is to design a Bio Medical device which is capable of detecting seizures and send notifications if any abnormalities occur. For future extension we want to optimize the working as well as make it as a carryable device which is equipped with a GSM module.</p>
 
# Working #
1. Muscle sensor collects the data from the electrodes.
2. The collected signals are then Amplified using instrumentation amplifier and passed through band pass filter.
3. The output analog signal is then passed to ESP8266.
4. The 10 bit resolution ADC converts the analog value to a digital value which ranges from 0 - 1023.
5. based on the threshold value the notification triggering action will take place.</br>

<b>"Note - Please refer graph_muscle.png to get a clear insight on working of muscle sensor"</b><br/>
