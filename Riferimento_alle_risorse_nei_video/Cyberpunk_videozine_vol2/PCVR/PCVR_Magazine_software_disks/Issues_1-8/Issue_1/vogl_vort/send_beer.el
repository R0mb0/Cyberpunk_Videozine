;;(PROGRAM) send_beer.el
;;(DESCRIPTION) Very Ordinary Beer Submission (Emacs Version)
;;(USAGE) emacs -load send_beer.el
;;(AUTHOR) Patrick Jordan
;;(CREATION DATE) 14/5/92
;;(ADDRESS) CSIRO Division of Radiophysics, Marsfield, NSW
;;(EMAIL) pjordan@rp.csiro.au


;;----------------------------------------------------------------------
;; This program may be freely anythinged.
;;----------------------------------------------------------------------

(mail)
(insert "echidna@munnari.oz.au")
(forward-line 1)
(end-of-line)
(insert "Beer Submission")
(forward-line 1)
(forward-line 1)
(insert "Dear Eric")
(insert "I thank you kindly for your free software and hope that you continue")
(insert "to produce work of this  kind. To support you I am sending you ")
(insert "<ENTER QUANTITY> cans of <ENTER BRAND>. ")
(forward-line 1)
(forward-line 1)
(insert "Best Regards,")
(forward-line 1)
(insert "<ENTER NAME>,")
(insert "<ENTER COMPANY>,")
(insert "<ENTER CONTACT>,")
(insert "<ENTER ADDRESS>,")
(insert "<ENTER PHONE>")


