.export ldptr10sp, ldptr1ysp
.importzp sp

; アンダースコアなしの生の内部システム関数として定義します
ldptr10sp:
    ldy #$00
ldptr1ysp:
    lda (sp),y
    tax
    iny
    lda (sp),y
    rts

