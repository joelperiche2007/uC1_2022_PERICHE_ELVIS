PROCESSOR 18F57Q84
#include "CONFIG_Bits.inc"  /config statements should precede project file includes./
#include <xc.inc>
     
PSECT udata_acs
 contador1: DS 1
 contador2: DS 1
 contador3: DS 1
    
PSECT resetVect,class=CODE,reloc=2
resetVect:
    goto Main 
    
PSECT CODE 
    
Main:
    CALL    Config_OSC,1
    CALL    Config_Port,1
    BSF     STATUS,5
    MOVLW   00000000B
    MOVWF   TRISD
    BCF     STATUS,5
     
Loop:
    CALL    Delay_500ms
    BTFSC   PORTA,3,0            ;PORTA<3> = 0? - Button press?
    GOTO    Conteo               ;
    
Deletreo:
    MOVLW   10001000B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop2
    MOVLW   10000011B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop2
    MOVLW   11000110B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop2
    MOVLW   10100001B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop2
    MOVLW   10000110B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop2
    MOVLW   10001110B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop2
    GOTO    Loop
    
Conteo:
    MOVLW   11000000B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   11111001B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   10100100B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   10110000B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   10011001B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   10010010B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   10000010B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   11111000B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   10000000B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    MOVLW   10011000B
    MOVWF   PORTD
    CALL    Delay_500ms
    CALL    Delay_500ms
    CALL    Loop1
    GOTO    Loop 
    
Loop1:
    BTFSS   PORTA,3,0           ;PORTA<3> = 0? - Button press?
    GOTO    Deletreo
    RETURN
    
Loop2:
    BTFSC   PORTA,3,0           ;PORTA<3> = 0? - Button press?
    GOTO    Conteo
    RETURN
    
 Config_OSC:
    ;Configuracion del oscilador interno a una frecuencia de 4MHz
    BANKSEL OSCCON1 
    MOVLW   0x60                ;Seleccionamos el bloque del osc con un div:1
    MOVWF   OSCCON1
    MOVLW   0x02                ; Seleccionamos una frecuencia de 4MHz
    MOVWF   OSCFRQ 
    RETURN
   
 Config_Port:  ;PORT-LAT-ANSEL-TRIS	    LED:RF3	BUTTON:RA3
    ;Config Led
    BANKSEL PORTD
    CLRF    PORTD,1	        ; PORTF = 0 
    BSF     LATD,7,1
    CLRF    ANSELD,1	        ; ANSELF<7:0> = 0 -PORT F DIGITAL
    BCF     TRISD,7,1

    ;Config Button
    BANKSEL PORTA
    CLRF    PORTA,1	        ; PORTA<7:0> = 0
    CLRF    ANSELA,1	        ; PortA digital
    BSF	    TRISA,3,1	        ; RA3 como entrada
    BSF	    WPUA,3,1	        ; Activamos la resistencia Pull-Up del pin RA3
    RETURN 
    
Delay_500ms:                    ;2Tcy -- Call
    MOVLW   50                  ;1Tcy -- k3
    MOVWF   contador3,0         ;1Tcy -- k3
; T = (6 + 4k)us         1Tcy = 1us
Ciclo3:
    MOVLW   10                  ;1Tcy -- k2
    MOVWF   contador2,0         ;k2Tcy 
Ext_Loop7:                      ;2Tcy -- Call
    MOVLW   250                 ;1Tcy - k1
    MOVWF   contador1,0         ;k1Tcy
Int_Loop7:
    NOP                         ;kTcy
    DECFSZ  contador1,1,0       ;(k1-1) + 3Tcy
    GOTO    Int_Loop7           ;(k1-1)*2Tcy
    DECFSZ  contador2,1,0       ;(k2-1) + 3Tcy
    GOTO    Ext_Loop7           ;(k2-1)*2Tcy
    DECFSZ  contador3,1,0       ;(k3-1) + 3Tcy
    GOTO    Ciclo3              ;(k3-1)*2Tcy
    RETURN                      ;2Tcy
    
END resetVect


