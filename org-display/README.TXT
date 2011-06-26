A simple program to display an HTML file in a window. It 
regularly reloads the file (every 60 seconds).

* HOW TO USE:

Assume that the file to monitor is: /tmp/agenda.html

** Run org-display /tmp/agenda.html

In my case I make the window sticky, and set the geometry via the window manager. 

** In emacs create a hook that writes the todo list or agenda to an
  HTML file every time you save an org file. It should write to /tmp/agenda.html

  This is my emacs code:

----------------------------------------------------------------------
;; that's the export function
(defun dmg-org-update-agenda-file (&optional force)
  (interactive)
  (save-excursion
    (save-window-excursion
      (let ((file "/tmp/agenda.html"))
        (org-agenda-list)
        (org-write-agenda file)))))


;; format to oputput the agenda
(setq org-agenda-exporter-settings
      '((ps-number-of-columns 2)
        (ps-portrait-mode t)
        (org-agenda-add-entry-text-maxlines 5)
        (htmlize-output-type 'font)))
----------------------------------------------------------------------

;; update agenda file after changes to org files
(defun dmg-org-mode-init ()
  (add-hook 'after-save-hook 'dmg-org-update-agenda-file t t))

;(add-hook 'org-mode-hook 'dmg-org-mode-init)

* BUILDING

----------------------------------------------------------------------
qmake org-display.pro 
make
----------------------------------------------------------------------

then copy the executable anywhere you want.

* TODO: 

** Only reload if the file has changed. In that case, wait a couple of
  seconds to make sure the process writing has ended.

** Give the option to change the monitoring frequency (currently every
  60 seconds).
