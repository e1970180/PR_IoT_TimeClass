#ifndef PR_IoT_TimeClass_h
#define PR_IoT_TimeClass_h

    #include <stdint.h>             //used for Limits of integer types
    #include <arduino.h>

    typedef int32_t IoTtime_t; // try to use http://playground.arduino.cc/code/time
    
    class	TimeClass { // try to use http://playground.arduino.cc/code/time
    	public:
    		IoTtime_t  now()        { return _epoch; }
    		
    		void	update() { 
    		    uint32_t t;
    		    uint16_t ts;
    			//noInterrupts();
    			t = millis();
    			//interrupts();
    			if (t < _lastMillis)  ts = (UINT32_MAX - _lastMillis + t)/1000 ; 
    				else 			  ts = (t - _lastMillis)/1000 ;
    			if (ts > 0) {
    				_epoch += ts;
    				_lastMillis = t;
    			}
    		};
          
    		void	set(IoTtime_t t) {
    			noInterrupts();
    			_epoch = t;
    			interrupts(); 
    		}

    	private:
    		uint32_t	_lastMillis = 0;
    		IoTtime_t	_epoch = 0;
    };
    
    extern	TimeClass	IoTtime;

#endif               
