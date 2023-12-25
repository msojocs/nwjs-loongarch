#endif

void AppUninstallDialogView::OnDialogCancelled() {
  uninstall_dialog()->OnDialogClosed(false /* uninstall */,
                                     false /* clear_site_data */,
                                     false /* report_abuse */);
}

void AppUninstallDialogView::OnDialogAccepted() {
  const bool clear_site_data =
      clear_site_data_checkbox_ && clear_site_data_checkbox_->GetChecked();
  const bool report_abuse_checkbox =
      report_abuse_checkbox_ && report_abuse_checkbox_->GetChecked();
  uninstall_dialog()->OnDialogClosed(true /* uninstall */, clear_site_data,
                                     report_abuse_checkbox);
}

void AppUninstallDialogView::OnWidgetInitialized() {

//----replace
#endif

void AppUninstallDialogView::OnDialogCancelled() {
#if BUILDFLAG(IS_CHROMEOS_ASH)
  uninstall_dialog()->OnDialogClosed(false /* uninstall */,
                                     false /* clear_site_data */,
                                     false /* report_abuse */);
#endif
}

void AppUninstallDialogView::OnDialogAccepted() {
#if BUILDFLAG(IS_CHROMEOS_ASH)
  const bool clear_site_data =
      clear_site_data_checkbox_ && clear_site_data_checkbox_->GetChecked();
  const bool report_abuse_checkbox =
      report_abuse_checkbox_ && report_abuse_checkbox_->GetChecked();
  uninstall_dialog()->OnDialogClosed(true /* uninstall */, clear_site_data,
                                     report_abuse_checkbox);
#endif
}

void AppUninstallDialogView::OnWidgetInitialized() {
