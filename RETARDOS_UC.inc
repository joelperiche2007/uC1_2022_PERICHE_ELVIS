; @file Retardos.inc
; @author PERICHE RUIZ ELVIS JOEL    
; @brief Librería con múltiples subrutinas de retardos, desde 10us hasta 250ms
; @date 09/01/2023
; @Version  v6.00
  



PSECT udata_acs
 ;contadores para los retardos 
contador1: DS	1		;reserva un bit en acces ram
contador2: DS	1		;reserva un bit en acces ram
    
PSECT CODE

    
; para 10us:  T = 6+4k
Delay_10us:			;2Tcy- Call
    MOVLW   1			;lleva 1Tcy
    MOVWF   contador1,0		;lleva 1Tcy

Delay_Loop:
    NOP				;lleva kxTcy
    DECFSZ  contador1,1,0	;lleva (k-1) + 3Tcy
    GOTO    Delay_Loop		;lleva (k-1) + 2Tcy
    RETURN			;lleva 2Tcy

    
;para 25us:  T = 7+3k
Delay_25us:			;2Tcy -- Call
    MOVLW   6			;lleva 1Tcy
    MOVWF   contador1,0		;lleva 1Tcy
    NOP				;lleva 1Tcy

Delay_Loop:		
    DECFSZ  contador1,1,0	;lleva (k-1) + 3Tcy
    GOTO    Delay_Loop		;lleva (k-1) + 2Tcy
    RETURN			;lleva 2Tcy

    
;para 50us:  T = 6+4k
Delay_50us:			;2Tcy -- Call
    MOVLW   11			;lleva 1Tcy
    MOVWF   contador1,0		;lleva 1Tcy

Delay_Loop:
    NOP				;lleva kxTcy
    DECFSZ  contador1,1,0	;lleva (k-1) + 3Tcy
    GOTO    Delay_Loop		;lleva (k-1)*2Tcy
    RETURN			;lleva 2Tcy

    
;para 100us:  T = 8+4k
Delay_100us:			;2Tcy -- Call
    MOVLW   23		    	;lleva 1Tcy
    MOVWF   contador1,0		;lleva 1Tcy
    NOP				;lleva 1Tcy
    NOP				;lleva 1Tcy

Delay_Loop:
    NOP				;lleva kxTcy
    DECFSZ  contador1,1,0	;lleva (k-1) + 3Tcy
    GOTO    Delay_Loop		;lleva (k-1)*2Tcy
    RETURN			;lleva 2Tcy

    
;para 200us:  T = 8+3k
Delay_200us:			;2Tcy - Call
    MOVLW   64			;lleva 1Tcy
    MOVWF   contador1,0		;lleva 1Tcy
    NOP				;lleva 1Tcy
    NOP				;lleva 1Tcy

Delay_Loop:
    DECFSZ  contador1,1,0	;lleva (k-1) + 3Tcy
    GOTO    Delay_Loop		;lleva (k-1)x2Tcy
    RETURN			;lleva 2Tcy

    
;para 250us:  T = 6+4k
Delay_250us:			;2Tcy -- Call
    MOVLW   61			;lleva 1Tcy
    MOVWF   contador1,0		;lleva 1Tcy

Delay_Loop:
    NOP				;lleva kxTcy
    DECFSZ  contador1,1,0	;lleva (k-1) + 3Tcy
    GOTO    Delay_Loop		;lleva (k-1)*2Tcy
    RETURN			;lleva 2Tcy

    
;para 500us:  T = 8+4k
Delay_500us:			;2Tcy -- Call
    MOVLW   123			;lleva 1Tcy
    MOVWF   contador1,0		;lleva 1Tcy
    NOP				;lleva 1Tcy
    NOP				;lleva 1Tcy

Delay_Loop:
    NOP				;lleva kxTcy
    DECFSZ  contador1,1,0	;lleva (k-1) + 3Tcy
    GOTO    Delay_Loop		;lleva (k-1)x2Tcy
    RETURN			;lleva 2Tcy

    
    
;para 1ms:  T = 8+4k
Delay_1ms:			;2Tcy -Call
    MOVLW   248			;lleva 1Tcy
    MOVWF   contador1,0		;lleva 1Tcy
    NOP				;lleva 1Tcy
    NOP				;lleva 1Tcy

Delay_Loop:
    NOP				;lleva kxTcy
    DECFSZ  contador1,1,0	;lleva (k-1) + 3Tcy
    GOTO    Delay_Loop		;lleva (k-1)x2Tcy
    RETURN			;lleva 2Tcy

    
    
;para 5ms:  T = 10+6n+4nk
Delay_5ms:			    ;2Tcy - Call
    MOVLW   5			    ;lleva 1Tcy
    MOVWF   contador2,0		    ;lleva 1Tcy
    NOP				    ;lleva 1Tcy
    NOP				    ;lleva 1Tcy

Ext_Loop:
    MOVLW   248			    ;lleva nxTcy
    MOVWF   contador1,0		    ;lleva nxTcy
    
Int_Loop:
    NOP				    ;lleva nxkxTcy
    DECFSZ  contador1,1,0	    ;lleva nx[(k-1) + 3Tcy]
    GOTO    Int_Loop		    ;lleva nx(k-1)*2Tcy
    NOP				    ;lleva nxTcy
    DECFSZ  contador2,1,0	    ;lleva (n-1) + 3Tcy
    GOTO    Ext_Loop		    ;lleva (n-1)x2Tcy
    NOP				    ;lleva 1Tcy
    NOP				    ;lleva 1Tcy
    RETURN			    ;lleva 2Tcy

    
;para 10ms:  T = 10+7n+4nk
Delay_10ms:			    ;2Tcy - Call
    MOVLW   10			    ;lleva 1Tcy
    MOVWF   contador2,0		    ;lleva 1Tcy
    NOP				    ;lleva 1Tcy
    NOP				    ;lleva 1Tcy

Ext_Loop:
    MOVLW   248			    ;lleva nxTcy
    MOVWF   contador1,0		    ;lleva nxTcy
    
Int_Loop:
    NOP				    ;lleva nxkxTcy
    DECFSZ  contador1,1,0	    ;lleva nx[(k-1) + 3Tcy]
    GOTO    Int_Loop		    ;lleva nx(k-1)x2Tcy
    NOP				    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    DECFSZ  contador2,1,0	    ;lleva (n-1) + 3Tcy
    GOTO    Ext_Loop		    ;lleva (n-1)x2Tcy
    NOP				    ;lleva 1Tcy
    NOP				    ;lleva 1Tcy
    RETURN			    ;lleva 2Tcy    

    
;para 25ms:  T = 6+8n+4nk
Delay_25ms:			    ;lleva 2Tcy - Call
    MOVLW   25			    ;lleva 1Tcy
    MOVWF   contador2,0		    ;lleva 1Tcy

Ext_Loop:
    MOVLW   248			    ;lleva nxTcy
    MOVWF   contador1,0		    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    
Int_Loop:
    NOP				    ;lleva nxkxTcy
    DECFSZ  contador1,1,0	    ;lleva nx[(k-1) + 3Tcy]
    GOTO    Int_Loop		    ;lleva nx(k-1)x2Tcy
    NOP				    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    DECFSZ  contador2,1,0	    ;lleva (n-1) + 3Tcy
    GOTO    Ext_Loop		    ;lleva (n-1)*2Tcy
    RETURN			    ;lleva 2Tcy        

    
;para 50ms:  T = 6+8n+4nk
Delay_50ms:			    ;2Tcy -Call
    MOVLW   50			    ;lleva 1Tcy
    MOVWF   contador2,0		    ;lleva 1Tcy

Ext_Loop:
    MOVLW   248			    ;lleva nxTcy
    MOVWF   contador1,0		    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    
Int_Loop:
    NOP				    ;lleva nxkxTcy
    DECFSZ  contador1,1,0	    ;lleva nx[(k-1) + 3Tcy]
    GOTO    Int_Loop		    ;lleva nx(k-1)x2Tcy
    NOP				    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    DECFSZ  contador2,1,0	    ;lleva (n-1) + 3Tcy
    GOTO    Ext_Loop		    ;lleva (n-1)*2Tcy
    RETURN			    ;lleva 2Tcy        

    
;para 100ms:  T = 6+8n+4nk
Delay_100ms:			    ;2Tcy - Call
    MOVLW   100			    ;lleva 1Tcy
    MOVWF   contador2,0		    ;lleva 1Tcy

Ext_Loop:
    MOVLW   248			    ;lleva nxTcy
    MOVWF   contador1,0		    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    
Int_Loop:
    NOP				    ;lleva nxkxTcy
    DECFSZ  contador1,1,0	    ;lleva nx[(k-1) + 3Tcy]
    GOTO    Int_Loop		    ;lleva nx(k-1)x2Tcy
    NOP				    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    DECFSZ  contador2,1,0	    ;lleva (n-1) + 3Tcy
    GOTO    Ext_Loop		    ;lleva (n-1)x2Tcy
    RETURN			    ;lleva 2Tcy        

    
;para 200ms: T = 6+8n+4nk
Delay_200ms:			    ;2Tcy -Call
    MOVLW   200			    ;lleva 1Tcy
    MOVWF   contador2,0		    ;lleva 1Tcy

Ext_Loop:
    MOVLW   248			    ;lleva nxTcy
    MOVWF   contador1,0		    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    
Int_Loop:
    NOP				    ;lleva nxkxTcy
    DECFSZ  contador1,1,0	    ;lleva nx[(k-1) + 3Tcy]
    GOTO    Int_Loop		    ;lleva nx(k-1)x2Tcy
    NOP				    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    DECFSZ  contador2,1,0	    ;lleva (n-1) + 3Tcy
    GOTO    Ext_Loop		    ;lleva (n-1)x2Tcy
    RETURN			    ;lleva 2Tcy        

    
;para 250ms: T = 6+8n+4nk
Delay_250ms:			    ;2Tcy -- Call
    MOVLW   250			    ;lleva 1Tcy
    MOVWF   contador2,0		    ;lleva 1Tcy

Ext_Loop:
    MOVLW   248			    ;lleva nxTcy
    MOVWF   contador1,0		    ;lleva nxTcy
    
Int_Loop:
    NOP				    ;lleva nxkxTcy
    DECFSZ  contador1,1,0	    ;lleva nx[(k-1) + 3Tcy]
    GOTO    Int_Loop		    ;lleva nx(k-1)x2Tcy
    NOP				    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    NOP				    ;lleva nxTcy
    DECFSZ  contador2,1,0	    ;lleva (n-1) + 3Tcy
    GOTO    Ext_Loop		    ;lleva (n-1)*2Tcy
    RETURN			    ;lleva 2Tcy
