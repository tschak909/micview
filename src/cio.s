	;; Call CIO

	.export _ciov, _open, _get, _clos, _getpalette
	.import _fn, _palette, _disp

_ciov:	LDX #$00
	JSR $E456
	RTS
	
_open:
	LDX #$20
	LDA #$03
	STA $0362
	LDA #<_fn
	STA $0364
	LDA #>_fn
	STA $0365
	LDA $7F
	STA $0368
	LDA $00
	STA $0369
	LDA #$04
	STA $036A
	LDA #$00
	STA $036B
	STA $036C
	STA $036D
	STA $036E
	STA $036F
	JSR $E456
	TYA
	RTS

_clos:
	LDX #$20
	LDA #$0C
	STA $0362
	JSR $E456
	RTS

_get:
	LDX #$20
	LDA #$07
	STA $0362
	LDA #$50
	STA $0364
	LDA #$31
	STA $0365
	LDA #$00
	STA $0368
	LDA #$1E
	STA $0369
	JSR $E456
	RTS

_getpalette:
	LDX #$20
	LDA #$07
	STA $0362
	LDA #<_palette
	STA $0364
	LDA #>_palette
	STA $0365
	LDA #$04
	STA $0368
	LDA #$00
	STA $0369
	JSR $E456
	RTS
