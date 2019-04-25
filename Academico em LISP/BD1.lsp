;;Iago Lourenço - 15610116
;;BD1.lsp


(setq bd1 'nil)

(setq bd1 (matricular '(iago mario julia) '(apc) 1 bd1))
(setq bd1 (matricular '(joao fernando) '(apc) 2 bd1))
(setq bd1 (matricular '(marcos) '(circuitos) 2 bd1))
(setq bd1 (matricular '(marcelo bruno beatriz) '(circuitos) 1 bd1))
(setq bd1 (matricular '(marcelo bruno beatriz) '(so) 1 bd1))
(setq bd1 (matricular '(paulo renata) '(so) 2 bd1))
(setq bd1 (vincular '(patricia angela) '(apc) bd1))
(setq bd1 (vincular '(dani) '(paradigmas circuitos) bd1))
(setq bd1 (vincular '(edmar) '(so) bd1))